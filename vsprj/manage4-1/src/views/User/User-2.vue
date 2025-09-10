<template>
    <div class="manage">
        <div class="manage-header">
            <el-button type="primary" @click="addUser()">+ 新增</el-button>
            <CommonForm inline :formLabel="searchFormLabel" :form="searchFrom">
                <el-button type="primary" @click="config.page = 1; getList()">搜索</el-button>
            </CommonForm>
        </div>
        <CommonTable :tableData="tableData" :tableLabel="tableLabel" :config="config" @changePage="getList()"
            @edit="editUser" @del="delUser">
        </CommonTable>
    </div>
    <el-dialog :title="operateType === 'add' ? '新增用户' : '更新用户'" v-model="isShow">
        <common-form :formLabel="operateFormLabel" :form="operateForm" ref="form"></common-form>
        <template #footer>
            <el-button @click="isShow = false">取 消</el-button>
            <el-button type="primary" @click="confirm">确 定</el-button>
        </template>
    </el-dialog>
</template>

<script setup>
import http from "@/request/index.js"
import { ElMessage, ElMessageBox } from 'element-plus'
import { ref, reactive, onMounted } from 'vue'
import CommonTable from '../CommonTable.vue'
import CommonForm from "../CommonForm.vue"

const tableData = ref([])
const tableLabel = [
    {
        field: "name",
        label: "姓名",
    },
    {
        field: "age",
        label: "年龄",
    },
    {
        field: "sexLabel",
        label: "性别",
    },
    {
        field: "birth",
        label: "出生日期",
        width: 200,
    },
    {
        field: "addr",
        label: "地址",
        width: 320,
    },
]
const config = reactive({
    page: 1,
    total: 10, //总记录条数
    limit: 5,  //每页几条
    loading: false,
})
onMounted(() => { getList(); })
async function getList() {
    config.loading = true;
    // 搜索时，页码需要设置为1，才能正确返回数据，因为数据是从第一页开始返回的
    let name = searchFrom.value.keyword;
    console.log("name", name)
    // name ? (config.page = 1) : "";
    let res = await http
        .get("/api/user/getUser", {
            params: {
                page: config.page,
                limit: config.limit,
                name,
            },
        });
    console.log(res);
    tableData.value = res.list.map((item) => {
        item.sexLabel = item.sex === 0 ? "女" : "男";
        return item;
    });
    config.total = res.count;
    config.loading = false;
}

async function delUser(row) {
    console.log(row);
    try {
        let res = await ElMessageBox.confirm("此操作将永久删除该记录, 是否继续?", "提示", {
            confirmButtonText: "确定",
            cancelButtonText: "取消",
            type: "warning",
        });
        console.log("***res=", res);
        let res2 = await http.get("/api/user/del?id=" + row.id)
        // let res2 = await http.get("/api/user/del", {
        //     params: {
        //         id: row.id,
        //     },
        // });
        console.log(res2);
        ElMessage({
            type: "success",
            message: "删除成功!",
        });
        getList();

    } catch (error) {
        console.log(error)
        ElMessage({
            type: "info",
            message: "已取消删除",
        });
    }
}

function delUser2(row) {
    ElMessageBox.confirm("此操作将永久删除该记录, 是否继续?", "提示", {
        confirmButtonText: "确定",
        cancelButtonText: "取消",
        type: "warning",
    }).then(() => {
        let id = row.id;
        http.get("/api/user/del", {
            params: {
                id,
            },
        }).then((res) => {
            console.log(res);
            ElMessage({
                type: "success",
                message: "删除成功!",
            });
            getList();
        });
    }).catch(() => {
        ElMessage({
            type: "info",
            message: "已取消删除",
        });
    });
}

const searchFrom = ref({
    keyword: "",
})
const searchFormLabel = [
    {
        field: "keyword",
        label: "",
    },
]

const operateType = ref("add")
const isShow = ref(false)

const dataDefault = () => {
    return {
        name: "",
        addr: "",
        age: "",
        birth: "",
        sex: "",
    }
}
const operateForm = ref(dataDefault())

const operateFormLabel = [
    {
        field: "name",
        label: "姓名",
    },
    {
        field: "age",
        label: "年龄",
    },
    {
        field: "sex",
        label: "性别",
        type: "select",
        opts: [
            {
                label: "男",
                value: 1,
            },
            {
                label: "女",
                value: 0,
            },
        ],
    },
    {
        field: "birth",
        label: "出生日期",
        type: "date",
    },
    {
        field: "addr",
        label: "地址",
    },
]

function addUser() {
    operateType.value = "add";
    // operateForm.value={};
    operateForm.value = dataDefault();
    isShow.value = true;
}

function editUser(row) {
    operateType.value = "edit";
    isShow.value = true;
    // operateForm.value = row;
    operateForm.value = { ...row }
}

/*新增或修改的确认 */
async function confirm() {
    let url = operateType.value === "edit" ? "/api/user/edit" : "/api/user/add"
    let res = await http.post(url, operateForm.value)
    console.log(res);
    isShow.value = false;
    getList();
    // form.resetFields();

}


</script>

<style lang="less" scoped>
.manage {
    padding-bottom: 20px;
    overflow: hidden;

    &-header {
        display: flex;
        // justify-content: space-between;
        align-items: flex-start;
    }
}
</style>