<template>
    <el-container style="height:100%;">
        <el-aside width="auto" style="overflow-y: hidden">
            <MyAside ref="aside" />
        </el-aside>
        <el-container style="overflow-y: hidden">
            <el-header>
                <MyHeader ref="header" />
            </el-header>
            <el-main>
                <router-view />
            </el-main>
        </el-container>
    </el-container>
</template>

<script setup>
import MyAside from './MyAside.vue'
import MyHeader from './MyHeader.vue';
</script>

<style lang="less" scoped></style>