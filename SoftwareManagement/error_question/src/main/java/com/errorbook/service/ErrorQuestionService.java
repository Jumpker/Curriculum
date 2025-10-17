package com.errorbook.service;

import com.errorbook.entity.ErrorQuestion;
import org.springframework.web.multipart.MultipartFile;

/**
 * 错题服务接口
 */
public interface ErrorQuestionService {
    
    /**
     * 添加错题
     * @param file 错题图片
     * @param subject 学科
     * @param knowledgePoint 知识点
     * @param wrongAnswer 错误答案
     * @param correctAnswer 正确答案
     * @param note 笔记
     * @return 添加的错题
     */
    ErrorQuestion addErrorQuestion(MultipartFile file, String subject, String knowledgePoint, 
                                  String wrongAnswer, String correctAnswer, String note);
    
    /**
     * OCR识别图片文字
     * @param file 图片文件
     * @return 识别的文本
     */
    String recognizeText(MultipartFile file);
}