import { ElMessage, ElMessageBox } from 'element-plus'
import http from "@/request/index.js"
import { reactive, onMounted } from "vue"


const useView = (props) => {
    const defaultOptions = {
        /** 获取表格数据url */
        getDataListURL: "",
        /** 删除数据url */
        deleteURL: "",
        /** 修改数据url */
        updateDataURL: "",
        /** 新增数据url */
        appendDataURL: "",

        loading: false,
        searchForm: {},  //存放查询字段
        dataList: [],
        page: 1,
        limit: 10,
        total: 0,

        //默认数据转换函数
        convert: (list) => list,
    }
    const state = reactive(Object.assign(defaultOptions, props))

    onMounted(() => { getList() })

    async function getList() {
        console.log("query()")
        if (!state.getDataListURL) {
            return;
        }

        let res = await http
            .get(state.getDataListURL, {
                params: {
                    page: state.page,
                    limit: state.limit,
                    ...state.searchForm,
                },
            });

        state.dataList = state.convert(res.list)
        state.total = res.count;
        state.loading = false;
    }

    async function delById(params) {
        console.log(params);
        try {
            let res = await ElMessageBox.confirm("此操作将永久删除该记录, 是否继续?", "提示", {
                confirmButtonText: "确定",
                cancelButtonText: "取消",
                type: "warning",
            });
            console.log("***res=", res);
            let res2 = await http.get(state.deleteURL, { params: params })
            console.log(res2);
            ElMessage({
                type: "success",
                message: "删除成功!",
            });
            getList();

        } catch (error) {
            console.log(error)
            ElMessage({
                type: "info",
                message: "已取消删除",
            });
        }
    }

    async function updateById(form) {
        let res = await http.post(state.updateDataURL, form)
        console.log(res);
    }

    async function append(form) {
        let res = await http.post(state.appendDataURL, form)
        console.log(res);
    }

    return {
        state, getList, delById, updateById, append,
    }

}

export default useView