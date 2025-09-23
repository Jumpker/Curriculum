package com.config;

import com.entity.Dog;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
@ConfigurationProperties(prefix = "dog")
public class DogeConfig {
    String name;
    int age;

    @Bean
    public Dog dog(){
        Dog d = new Dog();
        d.setName(name);
        d.setAge(age);
        return d;
    }
}
