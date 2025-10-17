# 错题本管理系统

## 项目简介

错题本管理系统是一个基于Spring Boot开发的Web应用，旨在帮助学生管理和复习错题。系统支持通过拍照上传错题，利用OCR技术自动识别题目内容，并提供错题的添加、查询、修改、删除等功能。

## 技术栈

- **后端**：Spring Boot 3.2.3
- **数据库**：MySQL
- **ORM框架**：Spring Data JPA
- **OCR技术**：百度OCR API
- **其他**：Lombok, Validation, FastJSON

## 功能特点

1. **错题管理**：添加、查询、修改、删除错题
2. **图片上传**：支持上传错题图片
3. **OCR识别**：自动识别图片中的文字内容
4. **知识点分类**：按学科和知识点分类错题
5. **熟练度标记**：支持1-5级熟练度标记，便于复习

## 系统架构

项目采用经典的三层架构：

- **控制层（Controller）**：处理HTTP请求，返回统一格式的响应
- **服务层（Service）**：实现业务逻辑
- **数据访问层（Repository）**：与数据库交互

## API接口说明

### 错题管理

#### 添加错题

- **URL**: `/api/error-questions`
- **方法**: POST
- **参数**:
  - `file`: 错题图片文件（必填）
  - `subject`: 学科（必填）
  - `knowledgePoint`: 知识点（必填）
  - `correctAnswer`: 正确答案（必填）
- **返回示例**:
```json
{
  "code": 200,
  "message": "成功",
  "data": {
    "id": 1,
    "subject": "数学",
    "knowledgePoint": "函数",
    "questionContent": "已识别的题目内容...",
    "correctAnswer": "x=2",
    "imagePath": "2023/04/15/abc123.jpg",
    "proficiencyLevel": 1,
    "isDeleted": false,
    "createTime": "2023-04-15T10:30:00",
    "updateTime": "2023-04-15T10:30:00"
  }
}
```

#### 查询所有错题

- **URL**: `/api/error-questions`
- **方法**: GET
- **返回示例**:
```json
{
  "code": 200,
  "message": "成功",
  "data": [
    {
      "id": 1,
      "subject": "数学",
      "knowledgePoint": "函数",
      "questionContent": "已识别的题目内容...",
      "correctAnswer": "x=2",
      "imagePath": "2023/04/15/abc123.jpg",
      "proficiencyLevel": 1,
      "isDeleted": false,
      "createTime": "2023-04-15T10:30:00",
      "updateTime": "2023-04-15T10:30:00"
    },
    // 更多错题...
  ]
}
```

#### 根据ID查询错题

- **URL**: `/api/error-questions/{id}`
- **方法**: GET
- **返回示例**: 同添加错题

#### 根据学科查询错题

- **URL**: `/api/error-questions/subject/{subject}`
- **方法**: GET
- **返回示例**: 同查询所有错题

#### 根据知识点查询错题

- **URL**: `/api/error-questions/knowledge-point/{knowledgePoint}`
- **方法**: GET
- **返回示例**: 同查询所有错题

#### 更新错题

- **URL**: `/api/error-questions/{id}`
- **方法**: PUT
- **参数**: 错题对象（JSON格式）
- **返回示例**: 同添加错题

#### 删除错题

- **URL**: `/api/error-questions/{id}`
- **方法**: DELETE
- **返回示例**:
```json
{
  "code": 200,
  "message": "成功",
  "data": null
}
```

#### 更新熟练度等级

- **URL**: `/api/error-questions/{id}/proficiency-level/{level}`
- **方法**: PUT
- **参数**:
  - `id`: 错题ID
  - `level`: 熟练度等级（1-5）
- **返回示例**:
```json
{
  "code": 200,
  "message": "成功",
  "data": null
}
```

## 配置说明

### 数据库配置

在`application.yml`中配置MySQL数据库连接信息：

```yaml
spring:
  datasource:
    driver-class-name: com.mysql.cj.jdbc.Driver
    url: jdbc:mysql://localhost:3306/error_question?useUnicode=true&characterEncoding=utf-8&serverTimezone=Asia/Shanghai
    username: root
    password: 123456
```

### OCR配置

在`application.yml`中配置百度OCR API信息：

```yaml
baidu:
  ocr:
    app-id: 你的百度OCR AppID
    api-key: 你的百度OCR API Key
    secret-key: 你的百度OCR Secret Key
```

### 文件上传配置

在`application.yml`中配置文件上传相关参数：

```yaml
spring:
  servlet:
    multipart:
      max-file-size: 10MB
      max-request-size: 10MB

file:
  upload-dir: ./uploads
```

## 启动说明

1. 确保已安装JDK 17或更高版本
2. 确保已安装并启动MySQL数据库
3. 修改`application.yml`中的数据库连接信息和百度OCR API信息
4. 执行以下命令启动应用：

```bash
./mvnw spring-boot:run
```

或者使用IDE直接运行`ErrorQuestionApplication`类

## 项目结构

```
error-question/
├── src/
│   ├── main/
│   │   ├── java/
│   │   │   └── com/
│   │   │       └── errorbook/
│   │   │           ├── config/           # 配置类
│   │   │           ├── controller/       # 控制器
│   │   │           ├── entity/           # 实体类
│   │   │           ├── repository/       # 数据访问层
│   │   │           ├── service/          # 服务接口
│   │   │           │   └── impl/         # 服务实现
│   │   │           └── ErrorQuestionApplication.java
│   │   └── resources/
│   │       ├── application.yml           # 应用配置文件
│   │       ├── static/                   # 静态资源
│   │       └── templates/                # 模板文件
│   └── test/                             # 测试代码
├── uploads/                              # 上传文件存储目录
├── pom.xml                               # Maven配置文件
└── README.md                             # 项目说明文档
```

## 注意事项

1. 首次运行时，系统会自动创建数据库表结构
2. 使用前请确保已申请百度OCR API并正确配置
3. 默认图片上传目录为项目根目录下的`uploads`文件夹
4. 熟练度等级范围为1-5，1表示最不熟练，5表示最熟练