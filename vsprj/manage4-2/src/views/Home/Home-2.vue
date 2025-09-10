<template>
  <el-row :gutter="10">
    <el-col :span="8">
      <el-card shadow="hover">
        <div class="user">
          <img :src="userImg" />
          <div class="userinfo">
            <p class="name">Nick</p>
            <p class="access">超级管理员</p>
          </div>
        </div>
        <div class="login-info">
          <p>上次登录时间：<span>2019-10-20</span></p>
          <p>上次登录地点：<span>北京</span></p>
        </div>
      </el-card>
      <el-card shadow="hover">
        <el-table :data="tableData">
          <el-table-column show-overflow-tooltip v-for="(val, key) in tableLabel" :key="key" :prop="key"
            :label="val"></el-table-column>
        </el-table>

      </el-card>
    </el-col>
    <el-col :span="16">
      <div class="num">
        <el-card shadow="hover" v-for="item in countData" :key="item.name" :body-style="{ display: 'flex', padding: 0 }">
          <el-icon :style="{ background: item.color }">
            <component :is="item.icon"></component>
            <!-- <Edit />  -->
          </el-icon>
          <!-- <i class="icon" :class="`el-icon-${item.icon}`" :style="{ background: item.color }"></i> -->
          <div class="detail">
            <p class="num">￥ {{ item.value }}</p>
            <p class="txt">{{ item.name }}</p>
          </div>
        </el-card>
      </div>

      <el-card shadow="hover">
        <EChart style="height: 280px" ref="order_chart"></EChart>
      </el-card>

      <div class="graph">
        <el-card shadow="hover">
          <EChart style="height: 260px" ref="user_chart"></EChart>
        </el-card>
        <el-card shadow="hover">
          <EChart style="height: 260px" ref="video_chart"></EChart>
        </el-card>
      </div>


    </el-col>
  </el-row>
</template>

<script setup>
import { ref, onMounted, getCurrentInstance } from "vue"
import http from "@/request/index";
import EChart from "../EChart.vue"
import userImg from "@/assets/images/user.png"

const instance = getCurrentInstance()
console.log("instance", instance)

const order_chart = ref()
const user_chart = ref()
const video_chart = ref()

const order_option = {
  xAxis: {
    type: "category",
    data: [],
  },
  yAxis: {
    type: "value",
  },
  series: [],
}

const user_option = {
  tooltip: {
    trigger: "axis",
    // axisPointer: {
    //   type: "cross",
    // },
  },

  xAxis: {
    type: "category",
    data: [],
  },
  yAxis: {
    type: "value",
  },
  series: [],
}
const video_option = {
  legend: {
    bottom: 20,
  },
  series: [],
}

const tableData = ref([])
const tableLabel = {
  name: "课程",
  todayBuy: "今日购买",
  monthBuy: "本月购买",
  totalBuy: "总购买",
}
const countData = [
  {
    name: "今日支付订单",
    value: 1234,
    icon: "Lock",
    color: "#2ec7c9",
  },
  {
    name: "今日收藏订单",
    value: 210,
    icon: "Star",
    color: "#ffb980",
  },
  {
    name: "今日未支付订单",
    value: 1234,
    icon: "Goods",
    color: "#5ab1ef",
  },
  {
    name: "本月支付订单",
    value: 1234,
    icon: "Lock",
    color: "#2ec7c9",
  },
  {
    name: "本月收藏订单",
    value: 210,
    icon: "Star",
    color: "#ffb980",
  },
  {
    name: "本月未支付订单",
    value: 1234,
    icon: "Goods",
    color: "#5ab1ef",
  },
]


async function getchartdata() {
  var res = await http.get("/home/getData");
  console.log("res", res);

  tableData.value = res.data.tableData;
  // 订单折线图
  const order = res.data.orderData;
  order_option.xAxis.data = order.date;
  // 第一步取出series中的name部分——键名
  let keyArray = Object.keys(order.data[0]);
  // 第二步，循环添加数据
  keyArray.forEach((key) => {
    order_option.series.push({
      name: key === "wechat" ? "小程序" : key,
      data: order.data.map((item) => item[key]),
      type: "line",
    });
  });
  // 用户柱状图
  user_option.xAxis.data = res.data.userData.map((item) => item.date);
  console.log("*****", user_option.xAxis.data)
  user_option.series.push({
    name: "新增用户",
    data: res.data.userData.map((item) => item.new),
    type: "bar",
  });
  user_option.series.push({
    name: "活跃用户",
    data: res.data.userData.map((item) => item.active),
    type: "line",
    barGap: 0,
  });
  // 视频饼图
  video_option.series.push({
    data: res.data.videoData,
    type: "pie",
  });

  instance.refs.order_chart.setOption(order_option);
  instance.refs.user_chart.setOption(user_option);
  instance.refs.video_chart.setOption(video_option);

}

onMounted(() => {
  getchartdata()
  console.log(order_chart)
})


</script>

<style lang="less" scoped>
.user {
  display: flex;
  align-items: center;
  padding-bottom: 20px;
  margin-bottom: 20px;
  border-bottom: 1px solid #ccc;

  img {
    width: 150px;
    height: 150px;
    border-radius: 50%;
    margin-right: 40px;
  }

  .userinfo {
    .name {
      font-size: 32px;
      margin-bottom: 10px;
    }

    .access {
      color: #999999;
    }
  }
}

.login-info {
  p {
    line-height: 28px;
    font-size: 14px;
    color: #999999;

    span {
      color: #666666;
      margin-left: 60px;
    }
  }
}

.num {
  display: flex;
  flex-wrap: wrap;
  justify-content: space-between;

  .el-card {
    width: 32%;
    margin-bottom: 20px;

    .el-icon {
      font-size: 30px;
      width: 110px;
      height: 110px;
      text-align: center;
      line-height: 110px;
      color: #fff;
    }

    .detail {
      margin-left: 15px;
      display: flex;
      flex-direction: column;
      justify-content: center;
      height: 110px;

      .num {
        font-size: 25px;
        margin-bottom: 10px;
      }

      .txt {
        font-size: 14px;
        text-align: center;
        color: #999999;
      }
    }

  }
}

.graph {
  margin-top: 20px;
  display: flex;
  justify-content: space-between;

  .el-card {
    width: 48%;
  }
}
</style>