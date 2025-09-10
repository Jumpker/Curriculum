<template>
    <header>
        <div class="l-content">
            <el-button plain icon="menu" size="small" @click="collapseMenu">
            </el-button>

            <div class="tabs">
                <el-tag :key="tag.name" size="small" v-for="(tag, index) in tab.tabsList" :closable="tag.name !== 'home'"
                    :disable-transitions="false" @close="handleClose(tag, index)" @click="changeTab(tag)"
                    :effect="$route.name === tag.name ? 'dark' : 'plain'">
                    {{ tag.label }}
                </el-tag>
            </div>
        </div>
        <div class="r-content">
            <el-dropdown trigger="click" size="mini">
                <span class="el-dropdown-link"><img :src="userImg" class="user" /></span>
                <template #dropdown>
                    <el-dropdown-menu>
                        <el-dropdown-item>个人中心</el-dropdown-item>
                        <el-dropdown-item @click="logout">退出</el-dropdown-item>
                    </el-dropdown-menu>
                </template>
            </el-dropdown>
        </div>
    </header>
</template>

<script setup>
import { useTabStore } from '@/stores/tab.js'
import { useUserStore } from '@/stores/user.js'
import { useRouter, useRoute } from 'vue-router'
import userImg from "../assets/images/user.png"

const tab = useTabStore()
const user=useUserStore()
const router = useRouter()

function collapseMenu() {
    tab.isCollapse = !tab.isCollapse;
}

function handleClose(tag, index) {
    tab.closeTab(tag);
    //切换到最后一个tab页
    router.push(tab.tabsList[tab.tabsList.length - 1].path);
    console.log(index);
}
function changeTab(item) {
    router.push({ path: item.path });
    tab.selectMenu(item);
}

function logout(){
    user.token=""
    router.push("/login")
}

</script>

<style lang="less" scoped>
header {
    display: flex;
    height: 100%;
    align-items: center;
    justify-content: space-between;
}

.l-content {
    display: flex;
    align-items: center;

    .el-button {
        margin-right: 20px;
    }

    .tabs {

        // padding: 20px;
        .el-tag {
            margin-right: 15px;
            cursor: pointer;
        }
    }
}

.r-content {
    .user {
        width: 40px;
        height: 40px;
        border-radius: 50%;
    }
}
</style>