package com.errorbook.service.impl;

import com.errorbook.entity.ErrorQuestion;
import com.errorbook.repository.ErrorQuestionRepository;
import com.errorbook.service.ErrorQuestionService;
import com.errorbook.service.FileService;
import com.errorbook.service.OcrService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

/**
 * 错题服务实现类
 */
@Service
public class ErrorQuestionServiceImpl implements ErrorQuestionService {

    @Autowired
    private ErrorQuestionRepository errorQuestionRepository;
    
    @Autowired
    private FileService fileService;
    
    @Autowired
    private OcrService ocrService;

    @Override
    @Transactional
    public ErrorQuestion addErrorQuestion(MultipartFile file, String subject, String knowledgePoint, 
                                         String wrongAnswer, String correctAnswer, String note) {
        // 保存图片
        String imagePath = fileService.saveImage(file);
        
        // OCR识别图片文字
        String questionContent = ocrService.recognizeText(file);
        
        // 创建错题对象
        ErrorQuestion errorQuestion = new ErrorQuestion();
        errorQuestion.setSubject(subject);
        errorQuestion.setKnowledgePoint(knowledgePoint);
        errorQuestion.setQuestionContent(questionContent);
        errorQuestion.setWrongAnswer(wrongAnswer);
        errorQuestion.setCorrectAnswer(correctAnswer);
        errorQuestion.setNote(note);
        errorQuestion.setImagePath(imagePath);
        errorQuestion.setProficiencyLevel(0); // 默认熟练度为0
        errorQuestion.setIsDeleted(false); // 默认未删除
        
        // 保存到数据库
        return errorQuestionRepository.save(errorQuestion);
    }

    @Override
    public String recognizeText(MultipartFile file) {
        return ocrService.recognizeText(file);
    }
}