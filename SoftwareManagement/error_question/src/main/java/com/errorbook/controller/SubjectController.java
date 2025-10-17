package com.errorbook.controller;

import com.errorbook.common.Result;
import com.errorbook.entity.Subject;
import com.errorbook.service.SubjectService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * 学科控制器
 */
@CrossOrigin(origins = "*")
@RestController
@RequestMapping("/api/subjects")
public class SubjectController {

    @Autowired
    private SubjectService subjectService;

    /**
     * 获取所有学科
     */
    @GetMapping
    public Result<List<Subject>> getAllSubjects() {
        List<Subject> subjects = subjectService.getAllSubjects();
        return Result.success(subjects);
    }

    /**
     * 创建新学科
     */
    @PostMapping
    public Result<Subject> createSubject(@RequestParam("name") String name) {
        try {
            Subject subject = subjectService.createSubject(name);
            return Result.success(subject);
        } catch (IllegalArgumentException e) {
            return Result.error(e.getMessage());
        }
    }
}