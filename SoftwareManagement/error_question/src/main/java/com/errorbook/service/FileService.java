package com.errorbook.service;

import org.springframework.web.multipart.MultipartFile;

/**
 * 文件服务接口
 */
public interface FileService {
    
    /**
     * 保存图片文件
     * @param file 图片文件
     * @return 保存后的文件路径
     */
    String saveImage(MultipartFile file);
}