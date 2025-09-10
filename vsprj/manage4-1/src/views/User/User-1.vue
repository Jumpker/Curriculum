<template>
    <div class="manage">
        <CommonTable :tableData="tableData" :tableLabel="tableLabel" :config="config" @changePage="getList()">
        </CommonTable>
    </div>
</template>

<script setup>
import http from "@/request/index.js"
import { ref, reactive, onMounted } from 'vue'
import CommonTable from '../CommonTable.vue'

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
    let name = ""
    // let name = searchFrom.value.keyword;
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