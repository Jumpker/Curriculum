<template>
    <el-form :inline="inline" :model="form" ref="form" label-width="100px">
        <el-form-item v-for="item in formLabel" :key="item.field" :label="item.label">
            <el-input v-model="form[item.field]" :placeholder="'请输入' + item.label" v-if="!item.type"></el-input>
            <el-select v-model="form[item.field]" placeholder="请选择" v-if="item.type === 'select'">
                <el-option v-for="item in item.opts" :key="item.value" :label="item.label" :value="item.value">
                </el-option>
            </el-select>
            <el-switch v-model="form[item.field]" v-if="item.type === 'switch'"></el-switch>
            <el-date-picker v-model="form[item.field]" type="date" placeholder="选择日期" v-if="item.type === 'date'"
                value-format="yyyy-MM-dd"> </el-date-picker>
        </el-form-item>
        <el-form-item>
            <slot></slot>
        </el-form-item>
    </el-form>
</template>

<script setup>
const props = defineProps({
    inline: Boolean,
    form: Object,
    formLabel: Array
})
</script>

<style lang="less" scoped></style>