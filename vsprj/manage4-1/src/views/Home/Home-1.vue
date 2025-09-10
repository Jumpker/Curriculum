<template>
  <div>
    <e-chart ref="order_chart" style="width: 100%; height: 280px"></e-chart>
    <div style="display: flex">
      <EChart ref="user_chart" style="width: 50%; height: 280px"></EChart>
      <EChart ref="video_chart" style="width: 50%; height: 280px"></EChart>
    </div>
  </div>
</template>

<script setup>
import { ref, onMounted, getCurrentInstance } from "vue"
import http from "@/request/index";
import EChart from "../EChart.vue"

const instance = getCurrentInstance()
console.log("instance", instance)

const order_chart = ref(null)
const user_chart = ref(null)
const video_chart = ref(null)

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


async function getchartdata() {
  var res = await http.get("/home/getData");
  console.log("res", res);
  

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

<style lang="less" scoped></style>