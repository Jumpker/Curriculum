import { ref } from 'vue'
import { defineStore } from 'pinia'

export const useTabStore = defineStore('tab', () => {
  const isCollapse = ref(false)
  const tabsList = ref([
    {
      path: "/home",
      name: "home",
      label: "首页",
      icon: "House"
    }])

  function selectMenu(item) {
    let result = tabsList.value.findIndex(obj => obj.name === item.name);
    if (result === -1) tabsList.value.push(item);
  }
  function closeTab(item) {
    let result = tabsList.value.findIndex(obj => obj.name === item.name);
    if (result >= 0) {
      tabsList.value.splice(result, 1);
    }

  }
  return { isCollapse, tabsList, selectMenu, closeTab }
}, {
  persist: {
    enabled: true,
    strategies: [
      {
        key: 'tab',
        storage: sessionStorage
      }
    ]
  }
})
