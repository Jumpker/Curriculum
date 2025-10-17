package com.errorbook.controller;

import com.errorbook.common.Result;
import com.errorbook.entity.ErrorQuestion;
import com.errorbook.service.ErrorQuestionService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

/**
 * 错题控制器
 */
@CrossOrigin(origins = "*")
@RestController
@RequestMapping("/api/error-questions")
public class ErrorQuestionController {

    @Autowired
    private ErrorQuestionService errorQuestionService;

    /**
     * 添加错题
     */
    @PostMapping
    public Result<ErrorQuestion> addErrorQuestion(
            @RequestParam("file") MultipartFile file,
            @RequestParam("subject") String subject,
            @RequestParam("knowledgePoint") String knowledgePoint,
            @RequestParam("wrongAnswer") String wrongAnswer,
            @RequestParam("correctAnswer") String correctAnswer,
            @RequestParam(value = "note", required = false) String note) {
        ErrorQuestion errorQuestion = errorQuestionService.addErrorQuestion(
                file, subject, knowledgePoint, wrongAnswer, correctAnswer, note);
        return Result.success(errorQuestion);
    }
    
    /**
     * OCR识别图片文字
     */
    @PostMapping("/ocr")
    public Result<String> recognizeText(@RequestParam("file") MultipartFile file) {
        String text = errorQuestionService.recognizeText(file);
        return Result.success(text);
    }
}