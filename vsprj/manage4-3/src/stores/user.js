import { ref } from 'vue'
import { defineStore } from 'pinia'

export const useUserStore = defineStore('user', () => {
  const token = ref("") //存放登录标记
  const menu=ref([]) //存放用户菜单
  const is_menu_loaded=ref(false) //判断用户是否刷新页面
  return { token,menu,is_menu_loaded}
},{
  persist: {
    enabled: true,
    strategies: [
      {
        key: 'user',
        storage: sessionStorage,
        paths: ['token', 'menu'] 
      }
    ]
  }
})
