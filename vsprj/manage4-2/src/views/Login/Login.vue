<template>
    <div style="padding: 20px">
        <el-form :model="form" label-width="120">
            <el-form-item label="用户名">
                <el-input v-model="form.username"></el-input>
            </el-form-item>
            <el-form-item label="密码">
                <el-input v-model="form.password" type="password"></el-input>
            </el-form-item>
            <el-form-item align="center">
                <el-button type="primary" @click="login">登录</el-button>
            </el-form-item>
        </el-form>
    </div>
</template>

<script setup>
import { ref } from 'vue'
import http from "@/request/index";
import { ElMessage } from 'element-plus'

import { useUserStore } from '@/stores/user.js'
import { useRouter, useRoute } from 'vue-router'

const user=useUserStore()
const router=useRouter()

const form = ref({
    username: 'admin',
    password: '123456',
})

async function login() {
    let res = await http.post('/api/permission/getMenu', form.value);
    // console.log(res);
    if (res.code === 20000) {
        //设置登录标记
        user.token = res.data.token;
        router.push({ path: '/home' })
    } else {
        ElMessage.warning(res.data.message)
    }
}


</script>

<style lang="less" scoped>
.el-form {
    width: 50%;
    margin: auto;
    padding: 45px;
    height: 450px;
    background-color: #fff;
}
</style>