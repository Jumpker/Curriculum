package com.errorbook.config;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Configuration;

@Data
@Configuration
@ConfigurationProperties(prefix = "ocr.baidu")
public class OcrConfig {
    private String appId;
    private String apiKey;
    private String secretKey;
}