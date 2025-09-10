<template>
    <el-menu :collapse="tab.isCollapse" :default-active="$route.path" class="el-menu-vertical-demo"
        background-color="#545c64" text-color="#fff" active-text-color="#ffd04b">
        <h3 v-show="isCollapse">广财</h3>
        <h3 v-show="!isCollapse">广财后台管理系统</h3>
        <el-menu-item :index="item.path" v-for="item in noChildren" :key="item.path" @click="clickMenu(item)">
            <el-icon>
                <component :is="item.icon"></component>
            </el-icon>
            <template #title>
                <span>{{ item.label }}</span>
            </template>
        </el-menu-item>
        <el-sub-menu :index="item.label" v-for="(item, index) in hasChildren" :key="index">
            <template #title>
                <el-icon>
                    <component :is="item.icon"></component>
                </el-icon>
                <span>{{ item.label }}</span>
            </template>
            <el-menu-item-group>
                <el-menu-item :index="subItem.path" v-for="(subItem, subIndex) in item.children" :key="subIndex"
                    @click="clickMenu(subItem)">
                    <el-icon>
                        <component :is="subItem.icon"></component>
                    </el-icon>
                    <template #title>
                        <span>{{ subItem.label }}</span>
                    </template>
                </el-menu-item>
            </el-menu-item-group>
        </el-sub-menu>
    </el-menu>
</template>

<script setup>
import { computed } from 'vue'
import { useTabStore } from '@/stores/tab.js'
import { useUserStore } from '@/stores/user.js'
import { useRouter,useRoute } from 'vue-router'

const tab = useTabStore()
const user = useUserStore()
const router=useRouter()

const asideMenu = [
    {
        path: "/home",
        name: "home",
        label: "首页",
        icon: "House"
    },
    {
        path: "/user",
        name: "user",
        label: "用户管理",
        icon: "User"
    },
    {
        label: "其他",
        icon: "Setting",
        children: [
            {
                path: "/other/page1",
                name: "page1",
                label: "页面1",
                icon: "Setting"
            },
            {
                path: "/other/page2",
                name: "page2",
                label: "页面2",
                icon: "Setting"
            }
        ]
    }
]

const menu = computed(() => {
    return user.menu
})
const noChildren = computed(() => {
    return menu.value.filter(item => !item.children)
})
const hasChildren = computed(() => {
    return menu.value.filter(item => item.children)
})
const isCollapse = computed(() => {
    return tab.isCollapse
})

function clickMenu(item) {
    // if (route.name != item.name) {}
    // router.push({ name: item.name });
    router.push({ path: item.path });
    tab.selectMenu(item)

}


</script>

<style lang="less" scoped>
.el-menu {
    height: 100%;
    border: none;

    h3 {
        color: #ffffff;
        text-align: center;
        line-height: 48px;
        margin: 0;
    }
}

.el-menu-vertical-demo:not(.el-menu--collapse) {
    width: 220px;
    // min-height: 300px;
}
</style>