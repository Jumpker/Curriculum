<template>
    <div class="common-table">
        <el-table :data="tableData" height="90%" stripe v-loading="config.loading">
            <el-table-column label="序号" width="85">
                <template #default="scope">
                    <!-- <span style="margin-left: 10px">{{ (config.page - 1) * config.limit + scope.$index + 1 }}</span> -->
                    <span style="margin-left: 10px">{{ (config.page - 1) * config.limit +scope.$index + 1 }} </span>
                </template>
            </el-table-column>
            <el-table-column show-overflow-tooltip v-for="item in tableLabel" :key="item.field" :label="item.label"
                :width="item.width ? item.width : 125" :prop="item.field">
                <!-- <template #default="scope">
                    <span style="margin-left: 10px">{{ scope.row[item.field] }}</span>
                </template> -->
            </el-table-column>
            <el-table-column label="操作" min-width="180">
                <template #default="{row}">
                    <el-button size="small" @click="handleEdit(row)">编辑</el-button>
                    <el-button size="small" type="danger" @click="handleDelete(row)">删除</el-button>
                </template>
            </el-table-column>
        </el-table>
        <el-pagination class="pager" layout="prev, pager, next" :total="config.total" v-model:current-page="config.page"
            @current-change="changePage" :page-size="config.limit">
        </el-pagination>
    </div>
</template>

<script setup>
const props = defineProps({
    tableData: Array,
    tableLabel: Array,
    config: Object
})

const emit = defineEmits(["edit","del","changePage"])
function handleEdit(row) {
    console.log("edit")
    // this.$parent.edit(row)
    emit('edit', row)
}

function handleDelete(row) {
    emit('del', row)
}
function changePage(page) {
    emit('changePage', page)
}


</script>

<style lang="less" scoped></style>