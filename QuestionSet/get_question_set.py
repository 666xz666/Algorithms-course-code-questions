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
        
        
# url = '你想要爬取的网页链接'
# response = requests.get(url)
# soup = BeautifulSoup(response.text, 'html.parser')

# # 假设我们想要爬取所有的段落
# paragraphs = soup.find_all('p')
# md_content = ''
# for p in paragraphs:
#     md_content += p.get_text() + '\n\n'
        
def get_html():
    pass
