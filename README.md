# C-programs-for-conversion-of-SAM-file-into-Fastq-files
These programs converts the SAM file containing paired end sequence reads into two Fastq files . It is helpful in case when the SAM file is truncated or it contains some errors , then samtools fails to convert such SAM files into respective Fastq files.

1) FilterSam.cpp - This program filters out the good reads and writes them into output.sam file and the reads that have error or are incomplete are written into the garbage.sam file .

2) Samtofq.cpp - This program converts the SAM file to two fastq files .
