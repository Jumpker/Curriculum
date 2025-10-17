package com.errorbook.service;

import org.springframework.web.multipart.MultipartFile;

/**
 * OCR服务接口
 */
public interface OcrService {
    
    /**
     * 识别图片中的文字
     * @param file 图片文件
     * @return 识别出的文字
     */
    String recognizeText(MultipartFile file);
}