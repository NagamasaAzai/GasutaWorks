class Array {
	public static void main(String args[]) {
		//Создание одномерного массива и вывод значений элементов на экране
		int nums[] = new int[10];
		int i;
		for(i = 0; i < 10; i++)
			nums[i] = i;
		for(i = 0; i < 10; i++)
			System.out.println("Элемент [" + i + "]: " + nums[i]);
		//Альт.способ инициализации массива
		int nums2[] = {54, 23, 71, 17, -34, -56, 89, 999, 2, 10};

		int min, max;
		min = max = nums2[0];
		for (i = 1; i < 10; i++) {
			if(nums2[i] < min) min = nums2[i];
			if(nums2[i] > max) max = nums2[i];
		}		
		System.out.println("Минимальное значение в массиве: " + min + "\n Максимальное значение в массиве: " + max);
		// Пузырьковая сортировка массива nums2
		int a, b, t;
		int size = 10;
		System.out.println("Массив до сортировки:");
		for (i = 0; i < size; i++)
			System.out.println(" " + nums2[i]);
		System.out.println();

		for(a=1; a < size; a++)
			for(b=size-1; b >= a; b--) {
				if(nums2[b-1] > nums2[b]) {
					t = nums2[b-1];
					nums2[b-1] = nums2[b];
					nums2[b] = t;
				}
			}
		System.out.println("Массив после сортировки:");
                for (i = 0; i < size; i++)
                        System.out.println(" " + nums2[i]);
	}
}