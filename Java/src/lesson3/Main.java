package src.lesson3;

import java.util.ArrayList;
import java.util.List;

interface Obsever {
    void update(String message);
}
interface Subject {
    void register(Obsever obsever);
    void remove(Obsever obsever);
    void notifyObserver(String message);
}

class WechatUser implements Obsever {
    public String name;

    public WechatUser(String name) {
        this.name = name;
    }

    @Override
    public void update(String message) {
        System.out.println(name + "收到消息：" + message);
    }
}

class WechatOfficalAccount implements Subject {
    private List<WechatUser> obsevers = new ArrayList<>();
    @Override
    public void register(Obsever obsever) {
        obsevers.add((WechatUser) obsever);
    }
    @Override
    public void remove(Obsever obsever) {
        obsevers.remove((WechatUser) obsever);
        System.out.println("公众号已移除订阅者：" + ((WechatUser) obsever).name);
    }
    @Override
    public void notifyObserver(String message) {
        for (WechatUser obsever : obsevers) {
            obsever.update(message);
        }
    }
    public void publishArticle(String title) {
        System.out.println("公众号发布新消息：" + title);
        notifyObserver(title);
    }
}

public class Main {
    public static void main(String[] args) {
        WechatOfficalAccount Jker = new WechatOfficalAccount();
        WechatUser XiHe = new WechatUser("熙禾");
        WechatUser momo = new WechatUser("momo");
        Jker.register(XiHe);
        Jker.register(momo);
        Jker.publishArticle("新的vlog已发布");
        Jker.publishArticle("最近发现有匿名不法分子关注了本公众号, 准备删除该用户");
        Jker.remove(momo);
    }
}
