<template>
    <div style="height: 100%" ref="chart">echart</div>
</template>

<script setup>
import * as echarts from 'echarts';
import { ref, onMounted,watch } from 'vue'

const chart = ref()
const props=defineProps({opt:Object})

let echart = null
onMounted(() => {
    echart = echarts.init(chart.value);
    echart.setOption(props.opt)
})

watch(() => props.opt, () => {
    console.log("***option update")
    echart.setOption(props.opt)
},{deep:true})

</script>

<style lang="less" scoped></style>