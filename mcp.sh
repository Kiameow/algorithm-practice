#!/bin/bash

echo "请输入文本:"
read input
echo "请输入复制次数:"
read count

for ((i = 0; i < count; i++)); do
    printf "%s" "$input"
done

