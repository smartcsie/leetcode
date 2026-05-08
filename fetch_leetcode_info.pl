#!/usr/bin/perl
use strict;
use warnings;

# 1. 讀取所有 solution 檔案中的複雜度資訊
my %stats;
foreach my $cpp_file (glob("solution/*.cpp")) {
    # 假設檔名格式為 Solution_0001.cpp
    if ($cpp_file =~ /Solution_(\d{4})\.cpp/) {
        my $id = $1;
        my ($time, $space) = ("-", "-");
        
        open(my $f, '<', $cpp_file) or next;
        while (<$f>) {
            $time  = $1 if $_ =~ /Time Complexity:\s*(.*)/i;
            $space = $1 if $_ =~ /Space Complexity:\s*(.*)/i;
        }
        close($f);
        $stats{$id} = { time => $time, space => $space };
    }
}

# 2. 讀取 README 並生成更新後的內容
my @new_readme;
open(my $fh, '<', 'README.md') or die "無法開啟 README: $!";
while (my $line = <$fh>) {
    # 匹配 Markdown 表格行，例如: | 0001 | ... |
    if ($line =~ /^\|\s*(\d{4})\s*\|/) {
        my $id = $1;
        if (exists $stats{$id}) {
            my $t = $stats{$id}->{time};
            my $s = $stats{$id}->{space};
            
            # 假設你在表格新增了一欄 "複雜度"
            # 或者你直接修改 "備註/標籤" 欄位
            # 這裡示範：如果該行原本沒有複雜度資訊，就補在最後一欄前
            $line =~ s/(Array|Hash Table|Math|Binary Search|Tree|Two Pointers|Linked List)/$1 <br> `T:$t S:$s`/;
        }
    }
    push @new_readme, $line;
}
close($fh);

# 3. 寫回 README
open(my $out, '>', 'README.md') or die $!;
print $out @new_readme;
close($out);

print "✅ README 複雜度已自動更新完成！\n";
