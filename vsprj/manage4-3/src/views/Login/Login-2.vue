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
import { ref,nextTick,onMounted } from 'vue'
import http from "@/request/index";
import { ElMessage } from 'element-plus'

import { useUserStore } from '@/stores/user.js'
import { useTabStore } from '@/stores/tab.js'
import { useRouter } from 'vue-router'
import {loadMenus} from "@/router/index.js"

const user = useUserStore()
const tab = useTabStore()

const router = useRouter()

const form = ref({
    username: 'admin',
    password: '123456',
})

onMounted(() => {
    // tab.tabsList=[]
    // user.menu=[]
    // sessionStorage.clear()
})
async function login() {
    let res = await http.post('/api/permission/getMenu', form.value);
    
    // console.log(res);
    if (res.code === 20000) {

        //设置登录标记
        user.menu = res.data.menu; //将用户菜单保存到pinia
        user.token = res.data.token;
        user.is_menu_loaded=false;  //设置菜单为未加载状态
        // loadMenus(res.data.menu) //添加动态路由
        ElMessage({type:'success',message:'正在登录，请稍候...',duration:1000})
        // setTimeout(()=>{router.push("/home")},3000)
        // nextTick(()=>{
        //     router.push("/home")
        // })
        router.push("/home")
        
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