export function MyTable(props, { slots, emit, attrs }) {
    // console.log("props=", props)
    // console.log("emit", emit)

    return <>
        <el-table data={props.data} stripe v-loading={props.loading}>
            <el-table-column label="序号">
                {{ default: ({ $index }) => <span>{(props.page - 1) * props.pageSize + $index + 1}</span> }}
            </el-table-column>
            {slots.default && slots.default()}
            <el-table-column label="操作" min-width="180">
                {{ default:({row})=>{ 
                    return <>
                    <el-button size="small" onClick={()=>props.onEdit(row)}>编辑</el-button>
                    <el-button size="small" type="danger" onClick={()=>props.onDel(row)}>删除</el-button>
                    </>
                    }  
                }}
            </el-table-column>

        </el-table>
        <el-pagination class="pager" layout="prev, pager, next"
            page-size={props.pageSize} total={props.total}
            current-page={props.page}
            onUpdate:current-page={(e) => {
                // console.log("e", e); 
                emit("update:page", e)
                props.onChangePage()
            }}
        >
        </el-pagination>
    </>

}