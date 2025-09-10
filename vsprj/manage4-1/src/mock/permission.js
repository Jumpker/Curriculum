import Mock from "mockjs";
export default {
  getMenu: config => {
    const { username, password } = JSON.parse(config.body);
    console.log(JSON.parse(config.body));
    // 先判断用户是否存在
    if (username === "admin" || username === "wp") {
      // 判断账号和密码是否对应
      if (username === "admin" && password === "123456") {
        return {
          code: 20000,
          data: {
            menu: [
              {
                path: "/",
                name: "home",
                label: "首页",
                icon: "s-home",
                url: "Home/Home2"
              },
              {
                path: "/home/user",
                name: "user",
                label: "用户管理页",
                icon: "user",
                url: "UserManage/UserManage"
              },
              {
                label: "其他",
                icon: "location",
                children: [
                  {
                    path: "/home/page1",
                    name: "page1",
                    label: "页面1",
                    icon: "setting",
                    url: "Other/PageOne"
                  },
                  {
                    path: "/home/page2",
                    name: "page2",
                    label: "页面2",
                    icon: "setting",
                    url: "Other/PageTwo"
                  }
                ]
              }
            ],
            token: Mock.Random.guid(),
            message: "获取成功"
          }
        };
      } else if (username === "wp" && password === "123456") {
        return {
          code: 20000,
          data: {
            menu: [
              {
                path: "/home",
                name: "home",
                label: "首页",
                icon: "s-home",
                url: "Home/Home2"
              },
            ],
            token: Mock.Random.guid(),
            message: "获取成功"
          }
        };
      } else {
        return {
          code: -999,
          data: {
            message: "密码错误"
          }
        };
      }
    } else {
      return {
        code: -999,
        data: {
          message: "用户不存在"
        }
      };
    }
  }
};
