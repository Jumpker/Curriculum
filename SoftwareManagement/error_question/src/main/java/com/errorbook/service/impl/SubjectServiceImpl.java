package com.errorbook.service.impl;

import com.errorbook.entity.Subject;
import com.errorbook.repository.SubjectRepository;
import com.errorbook.service.SubjectService;
import jakarta.annotation.PostConstruct;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.Arrays;
import java.util.List;

/**
 * 学科服务实现类
 */
@Service
public class SubjectServiceImpl implements SubjectService {

    @Autowired
    private SubjectRepository subjectRepository;

    @Override
    public List<Subject> getAllSubjects() {
        return subjectRepository.findAll();
    }

    @Override
    @Transactional
    public Subject createSubject(String name) {
        // 检查学科名称是否已存在
        if (subjectRepository.existsByName(name)) {
            throw new IllegalArgumentException("学科名称已存在: " + name);
        }
        
        // 创建新学科
        Subject subject = new Subject();
        subject.setName(name);
        subject.setIsDefault(false);
        
        return subjectRepository.save(subject);
    }

    @Override
    @Transactional
    @PostConstruct
    public void initDefaultSubjects() {
        // 如果没有默认学科，则创建
        if (subjectRepository.findByIsDefaultTrue().isEmpty()) {
            // 默认学科列表
            List<String> defaultSubjects = Arrays.asList(
                "语文", "数学", "英语", "物理", "化学", "生物", "政治", "历史", "地理"
            );
            
            // 创建默认学科
            for (String name : defaultSubjects) {
                if (!subjectRepository.existsByName(name)) {
                    Subject subject = new Subject();
                    subject.setName(name);
                    subject.setIsDefault(true);
                    subjectRepository.save(subject);
                }
            }
        }
    }
}