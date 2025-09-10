# 一、动态菜单注意事项 
## 1. 动态加载菜单到路由代码
   ```js
function  loadMenus(menu) {
  // console.log("!!!router",router.options.routes)
  const modules = import.meta.glob('@/views/**/*.vue')

  let homeMenu =
  {
      path: '/',
      name:'main',
      component: modules['/src/views/Main.vue'],
      children: [],
  }
  //添加子路由
  menu.forEach(item => {
      if (item.children) {
          let submenu = item.children.map(it => {
              return {
                  path: it.path,
                  name: it.name,
                  component: modules['/src/views/' + it.url + '.vue']
              }
          })
          homeMenu.children.push(...submenu)
      }
      else {
          homeMenu.children.push({
              path: item.path,
              name: item.name,
              component: modules['/src/views/' + item.url + '.vue']
          })
      }
  })
  router.addRoute(homeMenu);
  console.log("homeMenu",homeMenu)
}
   ``` 
注意：
* 需要执行import.meta.glob('@/views/**/*.vue')，这样vite才能将相应模块正确打包


## 2. 设置刷新检测标记
```js
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
```
## 3. 路由守卫检测菜单是否需要动态加载
```js
router.beforeEach((to, from, next) => {
  const user = useUserStore();
  let is_menu_loaded=user.is_menu_loaded; //默认是false，刷新页面这个也是false
  console.log("!!!to=",to,user.hasRoutes)
  if (to.name !== 'login' && user.token == '') next({ name: 'login' })
  else {
    if(!is_menu_loaded){
      console.log("***load dynamic router menu=",user.menu)
      loadMenus(user.menu)  //添加动态菜单到路由表
      user.is_menu_loaded=true  //更新菜单加载状态
      // console.log("***to=",to)
      next({ path:to.path, replace: true });
    }else{
      // console.log("!!! next()")
      next()  
    }
  }
})
``` 
注意：
* next()根据目前的路由表匹配的结果执行下一步
* next({})跳过当前的路由匹配结果，重新进行路由匹配
  

## 4. 登录页面
```js
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
``` 
注意：
* 获取动态菜单，并保存到pinia
* 路由跳转前，需要设置is_menu_loaded=false，避免用户在登录页面刷新页面，导致is_menu_loaded=true，从而使路由守卫那里的逻辑出现问题，导致菜单没有更新到路由中
  


