package com.errorbook.repository;

import com.errorbook.entity.ErrorQuestion;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

/**
 * 错题仓库接口
 */
@Repository
public interface ErrorQuestionRepository extends JpaRepository<ErrorQuestion, Long> {
    // 只保留基本的JPA Repository功能
}