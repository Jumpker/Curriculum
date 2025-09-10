<template>
    <div style="height: 100%" ref="chart">echart</div>
</template>

<script setup>
import * as echarts from 'echarts';
import { ref, onMounted, defineExpose } from 'vue'

const chart = ref()
let echart = null
onMounted(() => {
    echart = echarts.init(chart.value);
})

const setOption = (opt) => {
    echart.setOption(opt)
}

defineExpose({ echart, setOption })

</script>

<style lang="less" scoped></style>