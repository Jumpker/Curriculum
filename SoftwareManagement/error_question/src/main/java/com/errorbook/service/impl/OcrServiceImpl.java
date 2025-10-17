package com.errorbook.service.impl;

import com.baidu.aip.ocr.AipOcr;
import com.errorbook.config.OcrConfig;
import com.errorbook.service.OcrService;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

@Service
public class OcrServiceImpl implements OcrService {

    private AipOcr client;
    
    @Autowired
    public OcrServiceImpl(OcrConfig ocrConfig) {
        // 初始化百度OCR客户端
        client = new AipOcr(ocrConfig.getAppId(), ocrConfig.getApiKey(), ocrConfig.getSecretKey());
        // 设置网络连接参数
        client.setConnectionTimeoutInMillis(2000);
        client.setSocketTimeoutInMillis(60000);
    }

    @Override
    public String recognizeText(MultipartFile file) {
        try {
            // 传入可选参数
            HashMap<String, String> options = new HashMap<>();
            options.put("language_type", "CHN_ENG"); // 中英文混合
            options.put("detect_direction", "true"); // 检测图片方向
            options.put("detect_language", "true"); // 检测语言
            options.put("probability", "true"); // 返回识别结果中每一行的置信度
            
            // 调用通用文字识别接口
            JSONObject res = client.basicGeneral(file.getBytes(), options);
            
            // 解析识别结果
            StringBuilder text = new StringBuilder();
            if (res.has("words_result")) {
                Iterator<Object> it = res.getJSONArray("words_result").iterator();
                while (it.hasNext()) {
                    JSONObject word = (JSONObject) it.next();
                    text.append(word.getString("words")).append("\n");
                }
            }
            
            return text.toString();
        } catch (Exception e) {
            e.printStackTrace();
            return "OCR识别失败: " + e.getMessage();
        }
    }
}