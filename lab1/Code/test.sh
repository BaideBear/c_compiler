#!/bin/bash

# 遍历 ../Test 目录中的所有 .cmm 文件
for cmm_file in ../Test/*.cmm; do
    # 获取文件名（不含路径）和扩展名
    filename=$(basename "$cmm_file" .cmm)

    # 构造对应的 .exp 文件路径
    exp_file="../expects/${filename}.exp"

    # 执行 parser 命令，并将输出保存到一个临时文件
    ./parser "$cmm_file" > output.tmp

    # 检查 .exp 文件是否存在
    if [[ -f "$exp_file" ]]; then
        # 比对输出与 .exp 文件内容是否一致
        if cmp -s "$exp_file" output.tmp; then
            echo "Output matches for file ${filename}.cmm"
        else
            echo "Output does NOT match for file ${filename}.cmm"
        fi
    else
        # 如果 .exp 文件不存在，直接输出结果
        echo "No corresponding .exp file for ${filename}.cmm. Output is:"
        cat output.tmp
    fi

    # 删除临时文件
    rm output.tmp
done
