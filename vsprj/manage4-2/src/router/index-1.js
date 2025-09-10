import { createRouter, createWebHistory } from 'vue-router'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path:"/",
      component:() => import('../views/Main.vue'),
      children:[
        {
          path: '/home',
          alias:'/',
          name: 'home',
          component: () => import('../views/Home/Home-3.vue')
        },
        {
          path: '/user',
          name: 'user',
          component: () => import('../views/User/User-2.vue')
        },
        {
          path: '/other/page1',
          name: 'page1',
          component: () => import('../views/Other/Page1.vue')
        },
        {
          path: '/other/page2',
          name: 'page2',
          component: () => import('../views/Other/Page2.vue')
        },
      ]
    },
    {
      path:"/login",
      name:"login",
      component:()=>import("../views/Login/Login.vue")
    },
    {
      path:'/:pathMatch(.*)*', 
      name:'404',
      component:()=>import("../views/404.vue")
    }

  ]
})

export default router
