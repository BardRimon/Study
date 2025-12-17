# HWoptimisationMethods

## Как скачать все файлы из этой папки? / How to download all files from this folder?

---

### 🇷🇺 Русский

Есть несколько способов скачать все файлы из этой папки:

#### Способ 1: Скачать всю папку через GitHub UI

1. Перейдите на главную страницу репозитория: https://github.com/BardRimon/Study
2. Нажмите зеленую кнопку **Code** в правом верхнем углу
3. Выберите **Download ZIP**
4. Распакуйте архив и найдите папку `HWoptimisationMethods`

#### Способ 2: Клонировать весь репозиторий с помощью Git

```bash
git clone https://github.com/BardRimon/Study.git
cd Study/HWoptimisationMethods
```

#### Способ 3: Скачать только эту папку с помощью SVN

Если у вас установлен SVN, вы можете скачать только эту папку:

```bash
svn export https://github.com/BardRimon/Study/trunk/HWoptimisationMethods
```

#### Способ 4: Скачать только эту папку с помощью sparse-checkout (Git 2.25+)

```bash
git clone --filter=blob:none --sparse https://github.com/BardRimon/Study.git
cd Study
git sparse-checkout set HWoptimisationMethods
```

#### Способ 5: Скачать отдельные файлы

Вы можете скачать каждый файл отдельно, нажав на него и затем на кнопку **Download** или **Raw**:

- [1Перекрёсток.ipynb](https://raw.githubusercontent.com/BardRimon/Study/main/HWoptimisationMethods/1Перекрёсток.ipynb)
- [2optimisationsAdam.ipynb](https://raw.githubusercontent.com/BardRimon/Study/main/HWoptimisationMethods/2optimisationsAdam.ipynb)
- [3 task1 full difficulty.ipynb](https://raw.githubusercontent.com/BardRimon/Study/main/HWoptimisationMethods/3%20task1%20full%20difficulty.ipynb)
- [text.txt](https://raw.githubusercontent.com/BardRimon/Study/main/HWoptimisationMethods/text.txt)

---

### 🇬🇧 English

There are several ways to download all files from this folder:

#### Method 1: Download the entire folder via GitHub UI

1. Go to the main repository page: https://github.com/BardRimon/Study
2. Click the green **Code** button in the upper right corner
3. Select **Download ZIP**
4. Extract the archive and find the `HWoptimisationMethods` folder

#### Method 2: Clone the entire repository using Git

```bash
git clone https://github.com/BardRimon/Study.git
cd Study/HWoptimisationMethods
```

#### Method 3: Download only this folder using SVN

If you have SVN installed, you can download only this folder:

```bash
svn export https://github.com/BardRimon/Study/trunk/HWoptimisationMethods
```

#### Method 4: Download only this folder using sparse-checkout (Git 2.25+)

```bash
git clone --filter=blob:none --sparse https://github.com/BardRimon/Study.git
cd Study
git sparse-checkout set HWoptimisationMethods
```

#### Method 5: Download individual files

You can download each file individually by clicking on it and then clicking the **Download** or **Raw** button:

- [1Перекрёсток.ipynb](https://raw.githubusercontent.com/BardRimon/Study/main/HWoptimisationMethods/1Перекрёсток.ipynb)
- [2optimisationsAdam.ipynb](https://raw.githubusercontent.com/BardRimon/Study/main/HWoptimisationMethods/2optimisationsAdam.ipynb)
- [3 task1 full difficulty.ipynb](https://raw.githubusercontent.com/BardRimon/Study/main/HWoptimisationMethods/3%20task1%20full%20difficulty.ipynb)
- [text.txt](https://raw.githubusercontent.com/BardRimon/Study/main/HWoptimisationMethods/text.txt)

---

## Содержимое папки / Folder Contents

- **1Перекрёсток.ipynb** - Jupyter notebook with optimization exercises
- **2optimisationsAdam.ipynb** - Jupyter notebook covering Adam optimization
- **3 task1 full difficulty.ipynb** - Advanced optimization tasks
- **text.txt** - Text file

## Требования / Requirements

Для работы с Jupyter notebooks вам понадобится / To work with Jupyter notebooks, you will need:
- Python 3.x
- Jupyter Notebook or JupyterLab
- Необходимые библиотеки (см. импорты в начале каждого notebook) / Required libraries (see imports at the beginning of each notebook)
