import { createRouter, createWebHistory } from 'vue-router'
import { useUserStore } from '@/stores/user.js'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: "/",
      component: () => import('../views/Main.vue'),
      children: [
        {
          path: '/home',
          alias: '/',
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
      path: "/login",
      name: "login",
      component: () => import("../views/Login/Login.vue")
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

router.beforeEach((to, from, next) => {
  const userStore = useUserStore();

  if (to.name !== 'login' && userStore.token == '') next({ name: 'login' })
  else next()
})

export default router
