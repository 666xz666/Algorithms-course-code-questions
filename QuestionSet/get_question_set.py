import html2text as ht
import requests
from bs4 import BeautifulSoup


def html_to_md(source_path,target_path):
    text_maker = ht.HTML2Text()
    # 读取html格式文件
    with open(source_path, 'r', encoding = 'utf-8') as f:
        htmlpage = f.read()
    # 处理html格式文件中的内容
    text = text_maker.handle(htmlpage)
    # 写入处理后的内容
    with open(target_path, 'w') as f:
        f.write(text)
        
if __name__ == '__main__':
    html_to_md('test.html','3-E.md')
    
