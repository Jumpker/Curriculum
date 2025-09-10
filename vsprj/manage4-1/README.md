# 零、vue3使用setup语法糖注意事项
(参考资料)[https://blog.csdn.net/weixin_47560151/article/details/125743252] 
* 引入组件将自动注册 
* 组件通信:在< script setup>中必须使用 defineProps 和 defineEmits API 来替代 props 和 emits 
* 需主动向父组件暴露子组件属性 ：defineExpose
* 访问路由实例组件信息：route和router

# 一、组合式Api使用ref
```html
<div style="height: 100%" ref="chart">echart</div>
```
```js
const chart = ref()
```
# 二、父组件访问子组件 
## 1. 子组件暴露属性或方法给父组件
```js
defineExpose({ echart, setOption })
```
## 2. 父组件通过refs访问子组件
```js
import { ref, onMounted, getCurrentInstance } from "vue"
const instance = getCurrentInstance()
instance.refs.order_chart.setOption(order_option);
```

# 三、ECharts组件的两种封装思路 
1. 将setOption方法交给父组件调用 
2. 通过属性将option从父组件传给子组件，子组件通过watch调用setOption 


# 四、表单的清空 
1. Object.assign()
2. operateForm.value={}
3. 默认值
   ```js
const dataDefault = () => {
    return {
        name: "",
        addr: "",
        age: "",
        birth: "",
        sex: "",
    }
}
const operateForm = ref(dataDefault())

operateForm.value = dataDefault();
   ```




