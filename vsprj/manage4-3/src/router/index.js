import { createRouter, createWebHistory } from 'vue-router'
import { useUserStore } from '@/stores/user.js'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [ 
    // {
    //   path: "/",
    //   component: () => import('../views/Main.vue'),
    //   children: [
    //     {
    //       path: '/home',
    //       alias: '/',
    //       name: 'home',
    //       component: () => import('../views/Home/Home-3.vue')
    //     },
    //     {
    //       path: '/user',
    //       name: 'user',
    //       component: () => import('../views/User/User-2.vue')
    //     },
    //     {
    //       path: '/other/page1',
    //       name: 'page1',
    //       component: () => import('../views/Other/Page1.vue')
    //     },
    //     {
    //       path: '/other/page2',
    //       name: 'page2',
    //       component: () => import('../views/Other/Page2.vue')
    //     },
    //   ]
    // },
    {
      path:'/',
      redirect:"/login"
    },
    {
      path: "/login",
      name: "login",
      component: () => import("../views/Login/Login-2.vue")
    },
    {
      path: '/:pathMatch(.*)*',
      name: '404',
      component: () => import("../views/404.vue")
    }

  ]
})

//vuerouter访问pinia，需要注意的问题
//https://blog.csdn.net/youyacoder/article/details/127244318
//判断哪些页面不需要登录，可以用路由元信息

//动态路由刷新出现空白页
//原因：刷新页面的时候动态路由会刷新掉，然后动态路由会重新加载，而匹配路由会在加载路由之前，所以会导致空白页
//https://blog.csdn.net/qq_40315210/article/details/129692160

router.beforeEach((to, from, next) => {
  const user = useUserStore();
  let is_menu_loaded=user.is_menu_loaded; //默认是false，刷新页面这个也是false
  console.log("!!!to=",to,user.hasRoutes)
  if (to.name !== 'login' && user.token == '') next({ name: 'login' })
  else {
    if(!is_menu_loaded){
      console.log("***load dynamic router menu=",user.menu)
      loadMenus(user.menu);//添加动态菜单到路由表
      user.is_menu_loaded=true  //更新菜单加载状态
      // console.log("***to=",to)
      next({ path:to.path, replace: true });
    }else{
      // console.log("!!! next()")
      next()  
    }

  }
})

/**
 * 动态添加路由
 * https://segmentfault.com/q/1010000042205438/a-1020000042209450
 * https://www.cnblogs.com/fengmoliu/p/16223752.html
 */
function  loadMenus(menu) {
  // console.log("!!!router",router.options.routes)
  const modules = import.meta.glob('@/views/**/*.vue')
  // console.log("modules",modules)

  let homeMenu =
  {
      path: '/home',
      name:'main',
      component: modules['/src/views/Main.vue'],
      children: [],
  }
  //router.addRoute({ path: "/", component: modules['./Main.vue'] })
  //router.addRoute({ path: "/", component: () => import( /* @vite-ignore */ "../views/Main.vue") })
  //添加子路由
  menu.forEach(item => {
      if (item.children) {
          let submenu = item.children.map(it => {
              // item.component = () => import(`@/views/${item.url}.vue`)
              // console.log("url",it.url)
              return {
                  path: it.path,
                  name: it.name,
                  component: modules['/src/views/' + it.url + '.vue']
              }
          })
          // console.log("submenu",submenu)
          homeMenu.children.push(...submenu)
      }
      else {
          // console.log("url",item.url)
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

// function  loadMenus2(menu) {
//   // console.log("!!!router",router.options.routes)

//   let homeMenu =
//   {
//       path: '/',
//       name:'main',
//       component: () => import(`@/views/Main.vue`),
//       children: [],
//   }
//   //添加子路由
//   menu.forEach(item => {
//       if (item.children) {
//           let submenu = item.children.map(it => {
//               console.log("url",it.url)
//               return {
//                   path: it.path,
//                   name: it.name,
//                   component: () => import(`/src/views/${item.url}.vue`)
//               }
//           })
//           // console.log("submenu",submenu)
//           homeMenu.children.push(...submenu)
//       }
//       else {
//           homeMenu.children.push({
//               path: item.path,
//               name: item.name,
//               component: () => import(`/src/views/${item.url}.vue`)
//           })
//       }
//   })
//   // router.removeRoute("main")
//   router.addRoute(homeMenu);
//   // console.log("homeMenu",homeMenu)
// }

export { loadMenus}
export default router
