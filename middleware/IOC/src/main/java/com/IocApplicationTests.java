package com;

import com.entity.Dog;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.context.ApplicationContext;

import javax.annotation.Resource;
import java.util.Arrays;

@SpringBootTest
class IocApplicationTests {
    @Autowired
    Person p;
    Dog g;

    @Resource
    ApplicationContext context;

    @Test
    void t1() {
        System.out.println(p);
    }

    @Test
    void t2(){
        String[] names = context.getBeanDefinitionNames();
//        System.out.println(names);
        Arrays.asList(names).forEach(t->System.out.println(t));
    }

}
