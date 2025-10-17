package com.errorbook.entity;

import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.hibernate.annotations.CreationTimestamp;
import org.hibernate.annotations.UpdateTimestamp;

import java.time.LocalDateTime;

/**
 * 学科实体类
 */
@Data
@Entity
@Table(name = "subjects")
@NoArgsConstructor
@AllArgsConstructor
public class Subject {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false, unique = true)
    private String name; // 学科名称

    @Column(nullable = false)
    private Boolean isDefault = false; // 是否为系统默认学科

    @CreationTimestamp
    private LocalDateTime createTime; // 创建时间

    @UpdateTimestamp
    private LocalDateTime updateTime; // 更新时间
}