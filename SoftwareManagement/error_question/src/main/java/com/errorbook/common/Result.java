package com.errorbook.common;

import lombok.Data;

/**
 * 统一响应结果类
 */
@Data
public class Result<T> {
    private Integer code; // 状态码
    private String message; // 提示信息
    private T data; // 数据
    
    // 手动添加 getter 方法，确保JSON序列化正常工作
    public Integer getCode() {
        return code;
    }
    
    public String getMessage() {
        return message;
    }
    
    public T getData() {
        return data;
    }
    
    // 手动添加 setter 方法，解决符号问题
    public void setCode(Integer code) {
        this.code = code;
    }
    
    public void setMessage(String message) {
        this.message = message;
    }
    
    public void setData(T data) {
        this.data = data;
    }

    // 成功返回结果
    public static <T> Result<T> success() {
        return success(null);
    }

    // 成功返回结果
    public static <T> Result<T> success(T data) {
        Result<T> result = new Result<>();
        result.setCode(ResultCode.SUCCESS.getCode());
        result.setMessage(ResultCode.SUCCESS.getMessage());
        result.setData(data);
        return result;
    }

    // 失败返回结果
    public static <T> Result<T> error(String message) {
        Result<T> result = new Result<>();
        result.setCode(ResultCode.ERROR.getCode());
        result.setMessage(message);
        return result;
    }

    // 失败返回结果
    public static <T> Result<T> error(ResultCode resultCode) {
        Result<T> result = new Result<>();
        result.setCode(resultCode.getCode());
        result.setMessage(resultCode.getMessage());
        return result;
    }

    // 失败返回结果
    public static <T> Result<T> error(ResultCode resultCode, String message) {
        Result<T> result = new Result<>();
        result.setCode(resultCode.getCode());
        result.setMessage(message);
        return result;
    }
}