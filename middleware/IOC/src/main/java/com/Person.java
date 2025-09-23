package com;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Data
@Component(value = "zs")
@ConfigurationProperties(prefix = "person")
public class Person {
    String name;
    int age;
}
