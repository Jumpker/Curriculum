package com.errorbook.service.impl;

import com.errorbook.service.FileService;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.UUID;

@Service
public class FileServiceImpl implements FileService {

    // 图片保存路径，默认为项目根目录下的uploads文件夹
    @Value("${file.upload-dir:./uploads}")
    private String uploadDir;

    @Override
    public String saveImage(MultipartFile file) {
        try {
            // 创建日期目录，按年/月/日组织文件
            String datePath = LocalDate.now().format(DateTimeFormatter.ofPattern("yyyy/MM/dd"));
            Path dirPath = Paths.get(uploadDir, datePath);
            
            // 确保目录存在
            if (!Files.exists(dirPath)) {
                Files.createDirectories(dirPath);
            }
            
            // 生成唯一文件名
            String originalFilename = file.getOriginalFilename();
            String extension = originalFilename.substring(originalFilename.lastIndexOf("."));
            String filename = UUID.randomUUID().toString() + extension;
            
            // 保存文件
            Path filePath = dirPath.resolve(filename);
            Files.copy(file.getInputStream(), filePath);
            
            // 返回相对路径
            return datePath + "/" + filename;
        } catch (IOException e) {
            throw new RuntimeException("保存图片失败: " + e.getMessage());
        }
    }
}