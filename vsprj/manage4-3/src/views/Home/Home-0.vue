<template>
  <div id="chart" ref="chart" style="height:500px;"></div>
</template>

<script setup>
import { ref, onMounted } from "vue"
import http from "@/request/index";
import * as echarts from 'echarts';

const option = {
  title: {
    text: 'ECharts 入门示例'
  },
  tooltip: {},
  xAxis: {
    data: ['衬衫', '羊毛衫', '雪纺衫', '裤子', '高跟鞋', '袜子']
  },
  yAxis: {},
  series: [
    {
      name: '销量',
      type: 'bar',
      data: [5, 20, 36, 10, 10, 20]
    }
  ]

}
let myChart = null
const chart = ref(null)
onMounted(() => {
  // myChart = echarts.init(document.getElementById("chart"))
  myChart = echarts.init(chart.value)
  myChart.setOption(option)
})

async function getchartdata() {
  var res = await http.get("/home/getData");
  console.log(res);
}

onMounted(() => {
  getchartdata()
})


</script>

<style lang="less" scoped></style>