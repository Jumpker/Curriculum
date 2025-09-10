
export function MyForm(props, { slots, emit, attrs }) {
    console.log("Props", props)
    console.log("slots", slots)

    return <div>
        <el-form inline={props.inline} model={props.model} label-width="100px">
            {
                props.formLabel.map(({ field, label, type, opts }) => {
                    return <el-form-item label={label} >
                        { renderItem(props.model, field, label, type, opts) }
                    </el-form-item>
                })
            }
            {slots.default && slots.default()}
            {/* {slots.default ? slots.default() : null } */}

        </el-form>
    </div>
}

function renderItem(model, field, label, type, opts) {
    if (type === 'switch')
        return <el-switch v-model={model[field]} ></el-switch>
    else if (type == 'date')
        return <el-date-picker v-model={model[field]} type="date" placeholder="选择日期"
            value-format="yyyy-MM-dd"> </el-date-picker>
    else if (type === 'select')
        return <el-select v-model={model[field]} placeholder="请选择">
            {
                // console.log(opts)
            opts.map(({ label, value }) => { return <el-option label={label} value={value}></el-option> })
            }
        </el-select>
    else
        return <el-input v-model={model[field]} placeholder={`请输入${label}`}></el-input>
}
