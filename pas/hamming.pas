var
        a:array[1..100] of ansistring;
        s:ansistring;
        m,n,k,i,j,t:longint;
procedure nhap;
begin
        readln(n,m,k);
        readln(s);
        for i:=1 to k do
                readln(a[i]);
end;
procedure xuly;
var  min,count:longint;
begin
        s:=s+s;
        min:=maxlongint;
        for t:=1 to k do
                for i:=1 to 2*n-m+1 do
                begin
                        count:=0;
                        for j:=1 to m do
                        begin
                                if s[i+j-1]<>a[t][j] then inc(count);
                                if count>min then break;
                        end;
                        if count<min then min:=count;
                end;
        writeln(min);
end;
begin
        {assign(input,'hamming.inp');
        assign(output,'hamming.out');
        reset(input);
        rewrite(output);}
        nhap;
        xuly;
        {close(input);
        close(output);  }
end.