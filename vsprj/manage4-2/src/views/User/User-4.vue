<template>
    <div class="manage">
        <div class="manage-header">
            <el-button type="primary" @click="addUser()">+ 新增</el-button>
            <MyForm :inline="true" :formLabel="searchFormLabel" :model="state.searchForm">
                <el-button type="primary" @click="state.page = 1; getList()">搜索</el-button>
            </MyForm>
        </div>
        <MyTable :data="state.dataList" v-model:page="state.page" :total="state.total" :pageSize="state.limit"
            @changePage="getList()" @edit="editUser" @del="delById">
            <el-table-column label="姓名" prop="name"></el-table-column>
            <el-table-column label="年龄" prop="age"></el-table-column>
            <el-table-column label="性别" prop="sexLabel"></el-table-column>
            <el-table-column label="出生日期" prop="birth" width="200"></el-table-column>
            <el-table-column label="地址" prop="addr" width="320"></el-table-column>
        </MyTable>

    </div>
    <el-dialog :title="operateType === 'add' ? '新增用户' : '更新用户'" v-model="isShow">
        <MyForm :inline="false" :formLabel="dataFormLabel" :model="dataForm"></MyForm>
        <template #footer>
            <el-button @click="isShow = false">取 消</el-button>
            <el-button type="primary" @click="confirm">确 定</el-button>
        </template>
    </el-dialog>
    <el-date-picker
         
          type="dates"
          placeholder="Pick one or more dates"
        />
</template>

<script setup>
import { ref, reactive } from "vue"
import { MyForm } from '@/views/User/MyForm'
import { MyTable } from '@/views/User/MyTable'

import useView from "@/hooks/useView";

const option = {
    getDataListURL: "/api/user/getUser",
    deleteURL: "/api/user/del",
    updateDataURL: '/api/user/edit',
    appendDataURL: '/api/user/add',
    limit: 3,

    searchForm: {
        name: ""
    },

    convert: (list) => {
        list.map((it) => {
            it.sexLabel = it.sex === 0 ? "女" : "男";
            return it;
        })
        return list
    }

};

const { state, getList, delById, updateById, append } = useView(option)
// console.log("state",state)

const operateType = ref("add")
const isShow = ref(false)

/** 搜索框 */
const searchFormLabel = [
    {
        field: "name",
        label: "",
    },
]

/** 弹出框，编辑或新增字段 */
const dataFormLabel = [
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

const dataDefault = () => {
    return {
        name: "",
        addr: "",
        age: "",
        birth: "",
        sex: "",
    }
}

/** 弹出框，编辑或新增 */
// const dataForm=ref(dataDefault())
const dataForm = reactive(dataDefault())


function addUser() {
    operateType.value = "add";
    // dataForm.value = dataDefault();
    Object.assign(dataForm, dataDefault())
    isShow.value = true;
}

function editUser(row) {
    operateType.value = "edit";
    isShow.value = true;
    // dataForm.value = { ...row }
    Object.assign(dataForm, { ...row })

}

/*新增或修改的确认 */
async function confirm() {
    let fn = operateType.value === "edit" ? updateById : append
    // let res = await fn(dataForm.value)
    let res = await fn(dataForm)
    console.log(res);
    isShow.value = false;
    getList();
}


</script>

<style lang="less" scoped>
.manage {
    padding-bottom: 20px;
    overflow: hidden;

    &-header {
        display: flex;
        // justify-content: space-between;
        align-items: center;
    }
}
</style>