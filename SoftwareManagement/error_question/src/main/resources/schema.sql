-- 创建学科表
CREATE TABLE IF NOT EXISTS subjects (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL UNIQUE,
    is_default BOOLEAN NOT NULL DEFAULT FALSE,
    create_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    update_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

-- 创建错题表
CREATE TABLE IF NOT EXISTS error_questions (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    subject VARCHAR(50) NOT NULL,
    knowledge_point VARCHAR(100) NOT NULL,
    question_content TEXT,
    wrong_answer TEXT,
    correct_answer TEXT,
    note TEXT,
    image_path VARCHAR(255) NOT NULL,
    proficiency_level INT NOT NULL DEFAULT 0,
    is_deleted BOOLEAN NOT NULL DEFAULT FALSE,
    create_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    update_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

-- 插入默认学科数据
INSERT INTO subjects (name, is_default) VALUES 
('语文', TRUE),
('数学', TRUE),
('英语', TRUE),
('物理', TRUE),
('化学', TRUE),
('生物', TRUE),
('政治', TRUE),
('历史', TRUE),
('地理', TRUE);