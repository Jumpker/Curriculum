package com.errorbook.entity;

import jakarta.persistence.*;
import lombok.AllArgsConstructor;

import lombok.Data;
import lombok.NoArgsConstructor;
import org.hibernate.annotations.CreationTimestamp;
import org.hibernate.annotations.UpdateTimestamp;

import java.time.LocalDateTime;

/**
 * 错题实体类
 */
@Data
@Entity
@Table(name = "error_questions")
@NoArgsConstructor
@AllArgsConstructor
public class ErrorQuestion {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false)
    private String subject; // 学科

    @Column(nullable = false)
    private String knowledgePoint; // 知识点

    @Column(columnDefinition = "TEXT")
    private String questionContent; // 题目内容（OCR识别的文本）

    @Column(columnDefinition = "TEXT")
    private String wrongAnswer; // 错误答案

    @Column(columnDefinition = "TEXT")
    private String correctAnswer; // 正确答案

    @Column(columnDefinition = "TEXT")
    private String note; // 笔记

    @Column(nullable = false)
    private String imagePath; // 图片路径

    @Column(nullable = false)
    private Integer proficiencyLevel = 0; // 熟练度等级，默认为0（0-5）

    @Column(nullable = false)
    private Boolean isDeleted = false; // 逻辑删除标志，默认为false（1表示未删除）

    @CreationTimestamp
    private LocalDateTime createTime; // 创建时间

    @UpdateTimestamp
    private LocalDateTime updateTime; // 更新时间
}