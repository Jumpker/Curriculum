package com.errorbook.service;

import com.errorbook.entity.Subject;
import java.util.List;

/**
 * 学科服务接口
 */
public interface SubjectService {
    
    /**
     * 获取所有学科
     */
    List<Subject> getAllSubjects();
    
    /**
     * 创建新学科
     */
    Subject createSubject(String name);
    
    /**
     * 初始化默认学科
     */
    void initDefaultSubjects();
}