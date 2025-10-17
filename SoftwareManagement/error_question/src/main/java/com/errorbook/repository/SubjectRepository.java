package com.errorbook.repository;

import com.errorbook.entity.Subject;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;

/**
 * 学科仓库接口
 */
@Repository
public interface SubjectRepository extends JpaRepository<Subject, Long> {
    
    /**
     * 根据名称查找学科
     */
    Optional<Subject> findByName(String name);
    
    /**
     * 查找所有默认学科
     */
    List<Subject> findByIsDefaultTrue();
    
    /**
     * 查找所有非默认学科
     */
    List<Subject> findByIsDefaultFalse();
    
    /**
     * 检查学科名称是否存在
     */
    boolean existsByName(String name);
}